/**
 *Licensed to the Apache Software Foundation (ASF) under one
 *or more contributor license agreements.  See the NOTICE file
 *distributed with this work for additional information
 *regarding copyright ownership.  The ASF licenses this file
 *to you under the Apache License, Version 2.0 (the
 *"License"); you may not use this file except in compliance
 *with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing,
 *software distributed under the License is distributed on an
 *"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 *specific language governing permissions and limitations
 *under the License.
 */
/*
 * service_tracker_private.h
 *
 *  \date       Feb 6, 2013
 *  \author     <a href="mailto:dev@celix.apache.org">Apache Celix Project Team</a>
 *  \copyright  Apache License, Version 2.0
 */


#ifndef SERVICE_TRACKER_PRIVATE_H_
#define SERVICE_TRACKER_PRIVATE_H_

#include "service_tracker.h"

struct celix_serviceTracker {
	bundle_context_t *context;
	char * filter;

	service_tracker_pt tracker;
	service_tracker_customizer_pt customizer;
	service_listener_pt listener;

	celix_thread_rwlock_t lock; //projects trackedServices and untrackedServices
	array_list_t *trackedServices;
};

struct celix_tracked_entry {
	celix_thread_mutex_t lock;
	celix_thread_cond_t useCond;
	size_t useCount;
	service_reference_pt reference;
	void * service;
	properties_t *properties;
	bundle_t* serviceOwner;
};

typedef struct celix_tracked_entry celix_tracked_entry_t;

#endif /* SERVICE_TRACKER_PRIVATE_H_ */
