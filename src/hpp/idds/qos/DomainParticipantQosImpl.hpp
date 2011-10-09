#ifndef OMG_IDDS_QOS_DOMAIN_PARTICIPANT_QOS_IMPL_HPP_
#define OMG_IDDS_QOS_DOMAIN_PARTICIPANT_QOS_IMPL_HPP_

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

namespace idds {  namespace qos {
    class DomainParticipantQosImpl;
} }

class idds::qos::DomainParticipantQosImpl {
public:
    DomainParticipantQosImpl() { }

    DomainParticipantQosImpl(const ::dds::core::policy::UserData& user_data,
                             const ::dds::core::policy::EntityFactory& entity_factory)
    :  user_data_(user_data),
       entity_factory_(entity_factory)
    { }

    template <typename POLICY>
    const POLICY& policy() const;

    template <typename POLICY>
    POLICY& policy();


    void policy(const ::dds::core::policy::UserData& ud);
    void policy(const ::dds::core::policy::EntityFactory& efp);

protected:

private:
    ::dds::core::policy::UserData user_data_;
    ::dds::core::policy::EntityFactory entity_factory_;
};


#endif /* OMG_IDDS_DOMAIN_DOMAIN_PARTICIPANT_QOS_IMPL_HPP_ */
