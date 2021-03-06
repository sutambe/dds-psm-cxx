#ifndef OMG_DDS_DOMAIN_DETAIL_DOMAIN_ID_HPP_
#define OMG_DDS_DOMAIN_DETAIL_DOMAIN_ID_HPP_


#include <dds/domain/TDomainId.hpp>
#include <idds/domain/DomainIdImpl.hpp>



namespace dds { namespace domain { namespace detail {
    typedef dds::domain::TDomainId< idds::domain::DomainIdImpl> DomainId;
} } }

#endif /* OMG_DDS_DOMAIN_DETAIL_DOMAIN_ID_HPP_ */
