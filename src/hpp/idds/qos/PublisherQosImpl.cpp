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

#include <idds/qos/PublisherQosImpl.hpp>

namespace idds { namespace qos {

PublisherQosImpl::PublisherQosImpl() {}

PublisherQosImpl::PublisherQosImpl(const dds::core::policy::Presentation& presentation,
                                   const dds::core::policy::Partition& partition,
                                   const dds::core::policy::GroupData& gdata,
                                   const dds::core::policy::EntityFactory& factory_policy)
: presentation_(presentation),
  partition_(partition),
  gdata_(gdata),
  factory_policy_(factory_policy) { }

template<>
const dds::core::policy::Presentation&
PublisherQosImpl::policy<dds::core::policy::Presentation>() const {
    return presentation_;
}

template<>
const dds::core::policy::Partition&
PublisherQosImpl::policy<dds::core::policy::Partition>() const {
    return partition_;
}

template<>
const dds::core::policy::GroupData&
PublisherQosImpl::policy<dds::core::policy::GroupData>() const {
    return gdata_;
}

template<>
const dds::core::policy::EntityFactory&
PublisherQosImpl::policy<dds::core::policy::EntityFactory>() const {
    return factory_policy_;
}


void
PublisherQosImpl::policy(const dds::core::policy::Presentation& presentation) {
    presentation_ = presentation;
}

void
PublisherQosImpl::policy(const dds::core::policy::Partition& partition) {
    partition_ = partition;
}
void
PublisherQosImpl::policy(const dds::core::policy::GroupData& gdata) {
    gdata_ = gdata;
}

void PublisherQosImpl::policy(const dds::core::policy::EntityFactory& factory_policy)
{
    factory_policy_ = factory_policy;
}

} }
