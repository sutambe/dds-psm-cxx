#ifndef OMG_IDDS_QOS_PUBLISHER_QOS_IMPL_HPP_
#define OMG_IDDS_QOS_PUBLISHER_QOS_IMPL_HPP_

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

#include <dds/core/policy/CorePolicy.hpp>
#include <idds/pub/pubfwd.hpp>

namespace idds { namespace qos {

class PublisherQosImpl {
public:
    PublisherQosImpl();

    PublisherQosImpl(const dds::core::policy::Presentation& presentation,
                     const dds::core::policy::Partition& partition,
                     const dds::core::policy::GroupData& gdata,
                     const dds::core::policy::EntityFactory& factory_policy);

    template <typename POLICY>
    const POLICY& policy() const;

    template <typename POLICY>
    POLICY& policy();

public:
    void policy(const dds::core::policy::Presentation& presentation);
    void policy(const dds::core::policy::Partition& partition);
    void policy(const dds::core::policy::GroupData& gdata);
    void policy(const dds::core::policy::EntityFactory& factory_policy);

private:
    dds::core::policy::Presentation          presentation_;
    dds::core::policy::Partition             partition_;
    dds::core::policy::GroupData             gdata_;
    dds::core::policy::EntityFactory   factory_policy_;
};

} }
#endif /* OMG_IDDS_QOS_PUBLISHER_QOS_IMPL_HPP_ */
