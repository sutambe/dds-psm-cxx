#ifndef OMG_DDS_SUB_DETAIL_DATA_READER_HPP_
#define OMG_DDS_SUB_DETAIL_DATA_READER_HPP_

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


namespace dds { namespace sub { namespace detail {

template <typename T>
class DataReader {
public:
	DataReader(const dds::sub::Subscriber& pub,
		           const ::dds::topic::Topic<T>& topic) { }
	DataReader(const dds::sub::Subscriber& pub,
	           const ::dds::topic::Topic<T>& topic,
	           const dds::sub::qos::DataReaderQos& qos,
	           dds::sub::DataReaderListener<T>* listener,
               const dds::core::status::StatusMask& mask) { }
public:
    /**
     * Returns a <code>StatusCondition</code> instance associated with
     * this <code>Entity</code>.
     */
    template <typename SELF>
    ::dds::core::cond::StatusCondition<SELF>
    status_condition(const SELF& self) const {
        return ::dds::core::cond::StatusCondition<SELF>(
                new dds::core::cond::detail::StatusCondition<SELF>(self));
    }

public:
    dds::sub::LoanedSamples<T> take() {
        std::cout << "DataReader::take" << std::endl;
        return dds::sub::LoanedSamples<T>();
    }
};

} } }

#endif /* OMG_TDDS_SUB_DETAIL_DATA_READER_HPP_ */
