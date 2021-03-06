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
 * properties.h
 *
 *  \date       Apr 27, 2010
 *  \author    	<a href="mailto:dev@celix.apache.org">Apache Celix Project Team</a>
 *  \copyright	Apache License, Version 2.0
 */

#ifndef PROPERTIES_H_
#define PROPERTIES_H_

#include <stdio.h>

#include "hash_map.h"
#include "exports.h"
#include "celix_errno.h"
#ifdef __cplusplus
extern "C" {
#endif
typedef hash_map_pt properties_pt;
typedef hash_map_t properties_t;

UTILS_EXPORT properties_pt properties_create(void);

UTILS_EXPORT void properties_destroy(properties_pt properties);

UTILS_EXPORT properties_pt properties_load(const char *filename);

UTILS_EXPORT properties_pt properties_loadWithStream(FILE *stream);

UTILS_EXPORT properties_pt properties_loadFromString(const char *input);

UTILS_EXPORT void properties_store(properties_pt properties, const char *file, const char *header);

UTILS_EXPORT const char *properties_get(properties_pt properties, const char *key);

UTILS_EXPORT const char *properties_getWithDefault(properties_pt properties, const char *key, const char *defaultValue);

UTILS_EXPORT void properties_set(properties_pt properties, const char *key, const char *value);

UTILS_EXPORT celix_status_t properties_copy(properties_pt properties, properties_pt *copy);

#define PROPERTIES_FOR_EACH(props, key) \
    for(hash_map_iterator_t iter = hashMapIterator_construct(props); \
        hashMapIterator_hasNext(&iter), (key) = (const char*)hashMapIterator_nextKey(&iter);)
#ifdef __cplusplus
}
#endif

#endif /* PROPERTIES_H_ */
