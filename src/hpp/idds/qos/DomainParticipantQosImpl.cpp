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

#include <idds/qos/DomainParticipantQosImpl.hpp>

namespace idds { namespace qos {
template<>
const ::dds::core::policy::UserData&
DomainParticipantQosImpl::policy<dds::core::policy::UserData> () const {
    return user_data_;
}

template<>
const ::dds::core::policy::EntityFactory&
DomainParticipantQosImpl::policy<dds::core::policy::EntityFactory> () const {
    return entity_factory_;
}

void
DomainParticipantQosImpl::policy(const dds::core::policy::UserData& ud) {
    user_data_ = ud;
}

void
DomainParticipantQosImpl::policy(const dds::core::policy::EntityFactory& efp) {
    entity_factory_ = efp;
}

} }
