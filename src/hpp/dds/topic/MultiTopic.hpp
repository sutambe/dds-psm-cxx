#ifndef OMG_DDS_TOPIC_MULTI_TOPIC_HPP_
#define OMG_DDS_TOPIC_MULTI_TOPIC_HPP_

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

#include <vector>

#include <dds/core/detail/conformance.hpp>
#include <dds/core/types.hpp>
#include <dds/topic/topicfwd.hpp>
#include <dds/topic/TopicDescription.hpp>
#include <dds/topic/detail/MultiTopic.hpp>
#include <dds/domain/domainfwd.hpp>


namespace dds { namespace topic {

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

template <typename T, template <typename Q> class DELEGATE>
class MultiTopic : public TopicDescription<T, DELEGATE> {
public:
    OMG_DDS_REF_TYPE(MultiTopic, TopicDescription, DELEGATE<T>)

	virtual ~MultiTopic() { }

public:
    const std::string& subscription_expression() const {
		return this->delegate()->subscription_expression();
	}

    const dds::core::StringSeq expression_parameters() const {
		return this->delegate()->expression_parameters();
	}

    void expression_parameters(const dds::core::StringSeq& params) {
		this->delegate()->parameters(params);
	}
};

#endif  // OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

} }


#endif /* OMG_DDS_TOPIC_MULTI_TOPIC_HPP_ */
