/*
 * Copyright (C) 2023 Satoru Takeuchi <satoru.takeuchi@gmail.com>
 * Copyright (C) 2001-2003 Sistina Software (UK) Limited.
 *
 * This file is released under the GPL.
 *
 * This module modifies drivers/md/dm-linear.c in linux kernel.
 */

#include "dm.h"
#include <linux/module.h>
#include <linux/init.h>
#include <linux/blkdev.h>
#include <linux/bio.h>
#include <linux/slab.h>
#include <linux/device-mapper.h>

#define DM_MSG_PREFIX "simple"

struct simple_c {
	struct dm_dev *dev;
};

static int simple_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
	struct simple_c *sc;
	int ret;

	if (argc != 1) {
		ti->error = "Invalid argument count";
		return -EINVAL;
	}

	sc = kmalloc(sizeof(*sc), GFP_KERNEL);
	if (sc == NULL) {
		ti->error = "Cannot allocate context";
		return -ENOMEM;
	}

	ret = dm_get_device(ti, argv[0], dm_table_get_mode(ti->table), &sc->dev);
	if (ret) {
		ti->error = "Device lookup failed";
		goto err;
	}

	ti->num_flush_bios = 1;
	ti->num_write_same_bios = 1;
	ti->private = sc;
	return 0;

err:
	kfree(sc);
	return ret;
}

static void simple_dtr(struct dm_target *ti)
{
	struct simple_c *sc = (struct simple_c *) ti->private;

	dm_put_device(ti, sc->dev);
	kfree(sc);
}

static int simple_map(struct dm_target *ti, struct bio *bio)
{
	struct simple_c *sc = ti->private;

	bio_set_dev(bio, sc->dev->bdev);

	return DM_MAPIO_REMAPPED;
}

static int simple_iterate_devices(struct dm_target *ti,
                                  iterate_devices_callout_fn fn, void *data)
{
        struct simple_c *sc = ti->private;

        return fn(ti, sc->dev, 0, ti->len, data);
}

static struct target_type simple_target = {
	.name   = "simple",
	.version = {0, 0, 1},
	.features = DM_TARGET_NOWAIT | DM_TARGET_PASSES_CRYPTO,
	.module = THIS_MODULE,
	.ctr    = simple_ctr,
	.dtr    = simple_dtr,
	.map    = simple_map,
	.iterate_devices = simple_iterate_devices,
};

int __init dm_simple_init(void)
{
	int r = dm_register_target(&simple_target);

	if (r < 0)
		DMERR("register failed %d", r);

	return r;
}

void dm_simple_exit(void)
{
	dm_unregister_target(&simple_target);
}

module_init(dm_simple_init);
module_exit(dm_simple_exit);

MODULE_DESCRIPTION(DM_NAME "simple dm target");
MODULE_AUTHOR("Satoru Takeuchi <satoru.takeuchi@gmail.com>");
MODULE_LICENSE("GPL");
