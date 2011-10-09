#ifndef OMG_DDS_TOPIC_ANY_TOPIC_DESCRIPTION_HPP_
#define OMG_DDS_TOPIC_ANY_TOPIC_DESCRIPTION_HPP_

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

#include <dds/core/Exception.hpp>
#include <dds/topic/detail/AnyTopicDescription.hpp>


namespace dds { namespace topic {

class AnyTopicDescription {
public:
    template <typename T>
    inline AnyTopicDescription(const T& t)
    : holder_(new detail::TDHolder<T>(t)) { }

    const detail::TDHolderBase* operator->() const {
        return holder_;
    }

    detail::TDHolderBase* operator->() {
        return holder_;
    }

    inline ~AnyTopicDescription() {
        delete holder_;
    }

protected:
    inline AnyTopicDescription(detail::TDHolderBase* holder)
    : holder_(holder) { }

public:
    inline AnyTopicDescription& swap(AnyTopicDescription& rhs) {
        std::swap(holder_, rhs.holder_);
        return *this;
    }

    template <typename TOPIC>
    AnyTopicDescription& operator =(const TOPIC& rhs) {
        AnyTopicDescription(rhs).swap(*this);
        return *this;
    }

    inline AnyTopicDescription& operator =(AnyTopicDescription rhs) {
        rhs.swap(*this);
        return *this;
    }

public:
    template <typename T>
    const T& get() {
        detail::TDHolder<T>* h = dynamic_cast<detail::TDHolder<T>* >(holder_);
        if (h == 0) {
            throw dds::core::InvalidDowncastError("invalid type");
        }
        return h->get();
    }

protected:
    detail::TDHolderBase* holder_;
};

}}

#endif /* OMG_DDS_TOPIC_ANY_TOPIC_DESCRIPTION_HPP_ */
