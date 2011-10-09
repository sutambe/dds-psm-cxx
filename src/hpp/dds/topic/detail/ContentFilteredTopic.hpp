#ifndef OMG_DDS_TOPIC_DETAIL_CONTENTFILTEREDTOPIC_HPP_
#define OMG_DDS_TOPIC_DETAIL_CONTENTFILTEREDTOPIC_HPP_

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

#include <string>
#include <vector>

#include <dds/core/detail/conformance.hpp>
#include <dds/core/types.hpp>
#include <dds/topic/detail/topicfwd.hpp>
#include <idds/topic/TopicDescription.hpp>
#include <dds/topic/Topic.hpp>


namespace dds { namespace topic { namespace detail {

#ifdef OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

template <typename T>
class ContentFilteredTopic  : public idds::topic::TopicDescriptionImpl<T>
{
public:
    ContentFilteredTopic(const std::string& the_name,
                         const dds::topic::Topic<T>& the_topic,
                         const std::string& filter,
                         const dds::core::StringSeq& parameters,
                         const typename idds::topic::TopicDescriptionImpl<T>::DPHolder& dp)
    : idds::topic::TopicDescriptionImpl<T>(the_name,
                                           the_topic.type_name(),
                                           dp),
      topic_(the_topic),
      filter_(filter),
      params_(parameters) { }

	virtual ~ContentFilteredTopic() { }

public:
    const std::string& filter_expression() const {
		return filter_;
	}

    const dds::core::StringSeq expression_parameters() const {
		return params_;
	}

    void expression_parameters(const dds::core::StringSeq& params) {
		params_ = params;
	}

	dds::topic::Topic<T> topic() const {
		return topic_;
	}

private:
	dds::topic::Topic<T> topic_;
	std::string 		filter_;
	std::vector<std::string> params_;

};

#endif  // OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT

} } }


#endif /* OMG_DDS_TOPIC_DETAIL_CONTENTFILTEREDTOPIC_HPP_ */
