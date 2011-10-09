#ifndef OMG_DDS_SUB_DATA_READER_HPP_
#define OMG_DDS_SUB_DATA_READER_HPP_

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

#include <dds/core/TEntity.hpp>
#include <dds/sub/Subscriber.hpp>
#include <dds/sub/detail/DataReader.hpp>
#include <dds/sub/cond/ReadCondition.hpp>
#include <dds/sub/cond/QueryCondition.hpp>
#include <dds/topic/TopicDescription.hpp>
#include <dds/sub/status/ReaderState.hpp>
#include <dds/sub/Sample.hpp>


namespace dds { namespace sub {
    template <typename T, template <typename Q> class DELEGATE = detail::DataReader>
    class DataReader;
    
    template <typename T>
    DataReaderListener;
} }

template <typename T, template <typename Q> class DELEGATE>
class dds::sub::DataReader : public dds::core::TEntity< DELEGATE<T> > {
public:
	typedef T                                            	DataType;
    typedef ::dds::sub::Sample<T>                           Sample;
    typedef ::dds::sub::LoanedSamples<T>                    LoanedSamples;
	typedef ::dds::sub::DataReaderListener<DataType>        Listener;
	typedef ::dds::core::cond::StatusCondition<DataReader> 	StatusCondition;
	typedef ::dds::sub::cond::ReadCondition<DataType>      	ReadCondition;
	typedef ::dds::sub::cond::QueryCondition<DataType>      QueryCondition;
    typedef ::dds::sub::ReaderQuery<DataType>               ReaderQuery;

public:
	OMG_DDS_REF_TYPE(DataReader, dds::core::TEntity, DELEGATE<T>)
    
public:
    DataReader(const dds::sub::Subscriber& sub, 
               const dds::topic::Topic<T>& topic) : 
    ::dds::core::TEntity< DELEGATE<T> >(new DELEGATE<T>(sub, topic))
    { }
    
    
    DataReader(const dds::sub::Subscriber& pub,
               const ::dds::topic::Topic<T>& topic,
               const dds::sub::qos::DataReaderQos& qos,
               dds::sub::DataReaderListener<T>* listener = NULL,
               const dds::core::status::StatusMask& mask = ::dds::core::status::StatusMask::all()) :
    ::dds::core::TEntity< DELEGATE<T> >(new DELEGATE<T>(sub, 
                                                        topic,
                                                        qos,
                                                        listener,
                                                        mask))
    { }

public:
	~DataReader() { }

public:
	/**
	 * This operation allows access to the StatusCondition
	 * (Section 7.1.2.1.9, âStatusCondition Class) associated with the Entity.
	 * The returned condition can then be added to a WaitSet (Section 7.1.2.1.6,
	 * WaitSet Class) so that the application can wait for specific status changes
	 * that affect the Entity.
	 *
	 * @return the status condition
	 */
	StatusCondition status_condition() const {
		return this->impl()->template status_condition<DataReader>(*this);
	}

public:
	// == ReadState Management

	/**
	 * Returns the default read-state (if not changed, it is set to
     * ReaderState::any()).
	 */
	dds::sub::status::ReaderState default_read_state() {
		return this->impl()->read_state();
	}
	void default_read_state(const dds::sub::status::ReaderState& rs) {
		return this->impl()->read_state(rs);
	}
	//== Streaming read/take

	/**
	 * Manipulators are defined externally to make it possible to control whether the
	 * streaming operators reads or takes.
	 * dr >> read >> loanedSamples;
	 * dr >> take >> loanedSamples;
	 *
	 */
	DataReader& operator >>(dds::sub::LoanedSamples<T>& ls) {
		this->impl() >> ls;
	}

	///////////////////////////////////////////////////////////////////////
public:
	//== Loan Read/Take API ==================================================
	LoanedSamples read() {
		this->impl()->read();
	}

	LoanedSamples read(const ReaderQuery& query) {
		this->impl()->read(query);
	}

	LoanedSamples take() {
		return this->impl()->take();
	}

	LoanedSamples take(const ReaderQuery& query) {
		return this->impl()->take(query);
	}

	//== Copy Read/Take API ==================================================

    // --- Forward Iterators: --- //
	template <typename SamplesFWIterator, typename InfoFWIterator>
	void
	read(SamplesFWIterator sfit,
			InfoFWIterator ifit,
			size_t max_samples)
	{
		this->impl()->read(sfit, ifit, max_samples);
	}

	template <typename SamplesFWIterator, typename InfoFWIterator>
    void
    read(SamplesFWIterator sfit,
            InfoFWIterator ifit,
            size_t max_samples,
            const ReaderQuery& query)
    {
        this->impl()->read(sfit, ifit, max_samples, query);
    }

	template <typename SamplesFWIterator, typename InfoFWIterator>
	void
	take(SamplesFWIterator sfit,
			InfoFWIterator ifit,
			size_t max_samples)
	{
		this->impl()->take(sfit, ifit, max_samples);
	}

	template <typename SamplesFWIterator, typename InfoFWIterator>
    void
    take(SamplesFWIterator sfit,
            InfoFWIterator ifit,
            size_t max_samples,
            const ReaderQuery& query)
    {
        this->impl()->take(sfit, ifit, max_samples, query);
    }

    // --- Back-Inserting Iterators: --- //
	template <typename SamplesBIIterator, typename InfoBIIterator>
	void
	read(SamplesBIIterator sbit,
			InfoBIIterator ibit)
	{
		this->impl()->read(sbit, ibit);
	}

	template <typename SamplesBIIterator, typename InfoBIIterator>
    void
    read(SamplesBIIterator sbit,
            InfoBIIterator ibit,
            const ReaderQuery& query)
    {
        this->impl()->read(sbit, ibit, query);
    }


	template <typename SamplesBIIterator, typename InfoBIIterator>
	void
	take(SamplesBIIterator sbit,
			InfoBIIterator ibit)
	{
		this->impl()->take(sbit, ibit);
	}

	template <typename SamplesBIIterator, typename InfoBIIterator>
    void
    take(SamplesBIIterator sbit,
            InfoBIIterator ibit,
            const ReaderQuery& query)
    {
        this->impl()->take(sbit, ibit, query);
    }

    //========================================================================
    //== Instance Management
public:
    /**
     * This operation can be used to retrieve the instance key that corresponds
     * to an instance_handle. The operation will only fill the fields that form
     * the key inside the key_holder instance.
     * This operation may raise a BadParameter exception if the InstanceHandle
     * does not correspond to an existing data-object known to the DataWriter.
     * If the implementation is not able to check invalid handles, then the
     * result in this situation is unspecified.
     */
    dds::topic::TopicInstance<T>& key_value(dds::topic::TopicInstance<T>& i,
                                            const dds::core::InstanceHandle& h) {
        return this->delegate()->key_value(i, h);
    }

    /**
     * This operation can be used to retrieve the instance key that corresponds
     * to an instance_handle. The operation will only fill the fields that form
     * the key inside the key_holder instance.
     * This operation may raise a BadParameter exception if the InstanceHandle
     * does not correspond to an existing data-object known to the DataWriter.
     * If the implementation is not able to check invalid handles, then the
     * result in this situation is unspecified.
     */
    T& key_value(T& sample, const dds::core::InstanceHandle& h) {
        return this->delegate()->key_value(sample, h);
    }

    /**
     * This operation takes as a parameter an instance and returns a handle
     * that can be used in subsequent operations that accept an instance handle
     * as an argument. The instance parameter is only used for the purpose
     * of examining the fields that define the key. This operation does not
     * register the instance in question. If the instance has not been
     * previously registered, or if for any other reason the Service is unable
     * to provide an instance handle, the Service will return a TopicInstance
     * whose handle will be set to the HANDLE_NIL value.
     */
    const dds::core::InstanceHandle lookup_instance(const T& key) {
        return this->delegate()->lookup_instance(key);
    }

    //==========================================================================
public:
    dds::topic::TopicDescription<DataType> topic_description();

	// -- Listener Getter/Setter
	void listener(Listener* the_listener,
			const dds::core::status::StatusMask& event_mask);

	Listener* listener() const;

	// -- Qos Getter/Setter

	const dds::sub::qos::DataReaderQos
	qos() const {
		return this->impl()->qos();
	}

	void qos(const dds::sub::qos::DataReaderQos& the_qos) {
		this->impl()->qos(the_qos);
	}

	DataReader& operator <<(const dds::sub::qos::DataReaderQos& the_qos) {
		this->impl()->qos(the_qos);
		return *this;
	}

	DataReader& operator >> (dds::sub::qos::DataReaderQos& the_qos) {
		the_qos = this->impl()->qos();
		return *this;
	}

	void
	wait_for_historical_data(const dds::core::Duration& timeout) {
		this->impl()->wait_for_historical_data(timeout);
	}
	//////////////////////////////////////////////////////////////////////////
	// -- Condition API--
public:
    ReadCondition create_readcondition(
            const dds::sub::status::ReaderState& read_state =
                    dds::sub::status::ReaderState::any()) {
        return ReadCondition(new dds::sub::cond::detail::ReadConditionImpl<T>(
            typename dds::sub::cond::detail::ReadConditionImpl<T>::DRHolder(
                new dds::sub::detail::DataReaderHolder<T>(*this))));
    }

#ifdef  OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT
    QueryCondition create_querycondition(
            const std::string& query_expression,
            const dds::core::StringSeq& query_parameters,
            const dds::sub::status::ReaderState& read_state =
                    dds::sub::status::ReaderState::any()) {
        return QueryCondition(new dds::sub::cond::detail::QueryCondition<T>());
    }
#endif  // OMG_DDS_CONTENT_SUBSCRIPTION_SUPPORT
};


#endif /* OMG_DDS_SUB_DATA_READER_HPP_ */
