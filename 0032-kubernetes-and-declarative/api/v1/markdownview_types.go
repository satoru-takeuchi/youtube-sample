/*
Copyright 2021.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

package v1

import (
	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
)

// EDIT THIS FILE!  THIS IS SCAFFOLDING FOR YOU TO OWN!
// NOTE: json tags are required.  Any new fields you add must have json tags for the fields to be serialized.

// MarkDownViewSpec defines the desired state of MarkDownView
type MarkDownViewSpec struct {
	// MarkDowns contain the markdown files you want to display.
	// The key indicates the file name and must not overlap with the the keys.
	// The value is the content in markdown format.
	//+kubebuilder:validation:Required
	MarkDowns map[string]string `json:"markDowns,omitempty"`

	// Replicas is the number of viewers.
	// +kubebuilder:default=1
	// +optional
	Replicas int32 `json:"replicas,omitempty"`

	// ViewerImage is the image name of the viewer.
	// +optional
	ViewerImage string `json:"viewerImage,omitempty"`
}

// MarkDownViewStatus defines the observed state of MarkDownView
//+kubebuilder:validation:Enum=NotReady;Available;Healthy
type MarkDownViewStatus string

const (
	MarkDownViewNotReady  = MarkDownViewStatus("NotReady")
	MarkDownViewAvailable = MarkDownViewStatus("Available")
	MarkDownViewHealthy   = MarkDownViewStatus("Healthy")
)

//+kubebuilder:object:root=true
//+kubebuilder:subresource:status
//+kubebuilder:printcolumn:name="REPLICAS",type="integer",JSONPath=".spec.replicas"
//+kubebuilder:printcolumn:name="STATUS",type="string",JSONPath=".status"

// MarkDownView is the Schema for the markdownviews API
type MarkDownView struct {
	metav1.TypeMeta   `json:",inline"`
	metav1.ObjectMeta `json:"metadata,omitempty"`

	Spec   MarkDownViewSpec   `json:"spec,omitempty"`
	Status MarkDownViewStatus `json:"status,omitempty"`
}

//+kubebuilder:object:root=true

// MarkDownViewList contains a list of MarkDownView
type MarkDownViewList struct {
	metav1.TypeMeta `json:",inline"`
	metav1.ListMeta `json:"metadata,omitempty"`
	Items           []MarkDownView `json:"items"`
}

func init() {
	SchemeBuilder.Register(&MarkDownView{}, &MarkDownViewList{})
}
