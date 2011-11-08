#ifndef OMG_DDS_SUB_DATA_READER_HPP_
#define OMG_DDS_SUB_DATA_READER_HPP_

#include <dds/sub/TDataReader.hpp>
#include <dds/sub/detail/DataReader.hpp>


namespace dds { namespace sub {
	template <typename T, template <typename Q> class DELEGATE = dds::sub::detail::DataReader>
	class DataReader;

} }
#endif /* OMG_DDS_SUB_DATA_READER_HPP_ */
