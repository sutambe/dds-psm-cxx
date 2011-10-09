/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Corp.
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

#include <idds/core/InstanceHandleImpl.hpp>

namespace idds { namespace core {


InstanceHandleImpl::InstanceHandleImpl() : handle_(-1) {
    // empty
}
InstanceHandleImpl::InstanceHandleImpl(const dds::core::null_type& src)
: handle_(-1) { }

InstanceHandleImpl::~InstanceHandleImpl() { }

InstanceHandleImpl&
InstanceHandleImpl::operator=(const dds::core::null_type& src) {
	handle_ = -1;
	return *this;
}

bool
InstanceHandleImpl::is_nil() const {
	return (handle_ == -1);
}

} }
