#ifndef OMG_DDS_SUB_DETAIL_READ_CONDITION_HPP_
#define OMG_DDS_SUB_DETAIL_READ_CONDITION_HPP_

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

#include <dds/core/ref_traits.hpp>
#include <idds/core/ConditionImpl.hpp>


namespace dds { namespace sub { namespace cond { namespace detail {


template <typename T>
class ReadCondition : public idds::core::ConditionImpl {

//public:
//    typedef typename dds::core::smart_ptr_traits< dds::sub::detail::DataReaderHolder<T> >::ref_type
//    DRHolder;
//
//public:
//    ReadCondition(const DRHolder& reader) : reader_(reader) { }
//
//    virtual ~ReadConditionImpl() { }
//
//public:
//    const dds::sub::detail::DataReaderHolder<T>* parent() const {
//        return reader_.get();
//    }
//
//public:
//    // TODO
//
//private:
//    DRHolder reader_;
//
};

} } } }

#endif /* OMG_DDS_SUB_DETAIL_READ_CONDITION_HPP_ */
