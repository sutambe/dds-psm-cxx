#ifndef OMG_IDDS_CORE_POLICY_QOS_POLICY_COUNT_HPP_
#define OMG_IDDS_CORE_POLICY_QOS_POLICY_COUNT_HPP_

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

#include <dds/core/types.hpp>

namespace idds { namespace core { namespace policy {

class QosPolicyCountImpl {
public:
    QosPolicyCountImpl() { }

public:
    dds::core::policy::QosPolicyId policy_id() const {
        return policy_id_;
    }
    void policy_id(dds::core::policy::QosPolicyId id) {
        policy_id_ = id;
    }

    uint32_t count() const {
        return count_;
    }
    void count(uint32_t c) {
        count_ = c;
    }

private:
    dds::core::policy::QosPolicyId policy_id_;
    uint32_t count_;
};

} } }

#endif // !defined(OMG_IDDS_CORE_POLICY_QOS_POLICY_COUNT_HPP_)
