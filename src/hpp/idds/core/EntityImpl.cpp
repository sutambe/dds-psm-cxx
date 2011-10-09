/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Inc.
 * Copyright 2010, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <sstream>


#include <dds/core/Exception.hpp>
#include <dds/core/InstanceHandle.hpp>

#include <idds/core/EntityImpl.hpp>


volatile unsigned int idds::core::EntityImpl::entityID_ = 0;

idds::core::EntityImpl::EntityImpl()
: enabled_(true)
{ }

idds::core::EntityImpl::~EntityImpl()
{ }

void
idds::core::EntityImpl::enable() {
   // implementation-defined
}

const dds::core::status::StatusMask
idds::core::EntityImpl::status_changes() {
    throw dds::core::UnsupportedError("not implemented");
}

const dds::core::InstanceHandle
idds::core::EntityImpl::instance_handle() const {
   return dds::core::InstanceHandle(dds::core::null);
}



void
idds::core::EntityImpl::close() {  }

void
idds::core::EntityImpl::retain() {  }
