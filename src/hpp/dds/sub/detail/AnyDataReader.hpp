#ifndef OMG_DDS_SUB_DETAIL_ANY_DATAREADER_HPP_
#define OMG_DDS_SUB_DETAIL_ANY_DATAREADER_HPP_

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

#include <dds/sub/qos/DataReaderQos.hpp>
#include <dds/sub/Subscriber.hpp>

namespace dds { namespace sub { namespace detail {
class DRHolderBase {
public:
    virtual ~DRHolderBase();
    virtual const ::dds::sub::qos::DataReaderQos qos() const = 0;

    virtual void qos(const dds::sub::qos::DataReaderQos& qos) = 0;

    virtual const std::string topic_name() const = 0;

    virtual const std::string type_name() const = 0;

    virtual ::dds::sub::Subscriber parent() const = 0;

    virtual void close() = 0;

    // TODO: Add other non type-dependent methods.
};

template <typename DR>
class DRHolder : public DRHolderBase {
public:
    DRHolder(const DR& dr) : DR_(dr) { }
    virtual ~DRHolder() { }
public:
    virtual const dds::sub::qos::DataReaderQos qos() const {
        return DR_.qos();
    }

    virtual void qos(const dds::sub::qos::DataReaderQos& the_qos) {
    	DR_.qos(the_qos);
    }

    virtual const std::string topic_name() const {
        return DR_.topic().name();
    }

    virtual const std::string type_name() const {
        return DR_.topic().type_name();
    }

    virtual ::dds::sub::Subscriber parent() const {
        return parent();
    }

    virtual void close() {
        DR_.close();
    }

private:
    DR DR_;
};
} } }


#endif /* OMG_DDS_SUB_DETAIL_ANY_DATAREADER_HPP_ */
