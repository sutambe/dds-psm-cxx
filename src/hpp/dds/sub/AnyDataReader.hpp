#ifndef OMG_DDS_SUB_ANY_DATA_READER_HPP_
#define OMG_DDS_SUB_ANY_DATA_READER_HPP_

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
#include <dds/sub/subfwd.hpp>
#include <dds/sub/detail/AnyDataReader.hpp>

namespace dds { namespace sub {
class AnyDataReader {
public:
    template <typename DR>
    AnyDataReader(const DR& dr)  {
        holder_ = new detail::DRHolder<DR>(dr);
    }

    inline const detail::DRHolderBase* operator->() const {
        return holder_;
    }

    inline detail::DRHolderBase* operator->() {
        return holder_;
    }

    inline ~AnyDataReader() {
        delete holder_;
    }

public:
    inline AnyDataReader& swap(AnyDataReader& rhs) {
        std::swap(holder_, rhs.holder_);
        return *this;
    }

    template <typename TOPIC>
    AnyDataReader& operator =(const TOPIC& rhs) {
        AnyDataReader(rhs).swap(*this);
        return *this;
    }

    inline AnyDataReader& operator =(AnyDataReader rhs) {
        rhs.swap(*this);
        return *this;
    }

public:
    template <typename DR>
    const DR& get() {
        detail::DRHolder<DR>* h = dynamic_cast<detail::DRHolder<DR>* >(holder_);
        if (h == 0) {
            throw dds::core::InvalidDowncastError("invalid type");
        }
        return h->get();
    }
private:
    detail::DRHolderBase* holder_;
};

}}

#endif /* OMG_DDS_SUB_ANY_DATA_READER_HPP_ */
