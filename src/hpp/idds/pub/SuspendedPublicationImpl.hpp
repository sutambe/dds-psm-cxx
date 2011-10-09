#ifndef OMG_IDDS_PUB_SUSPENDED_PUBLICATION_IMPL_HPP_
#define OMG_IDDS_PUB_SUSPENDED_PUBLICATION_IMPL_HPP_

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

#include <iostream>

#include <idds/pub/pubfwd.hpp>


namespace idds { namespace pub {

class SuspendedPublicationImpl {
public:
    SuspendedPublicationImpl(const dds::pub::Publisher& t) : t_(t), ended_(false) {
        std::cout << "=== suspend publication" << std::endl;
    }
    void end() {
        if (!ended_) {
            std::cout << "=== resume publication" << std::endl;
            ended_ = true;
        }
    }
    ~SuspendedPublicationImpl() {
        if (!ended_) {
            this->end();
        }
    }

private:
    dds::pub::Publisher t_;
    bool ended_;
};

} }

#endif /* OMG_IDDS_PUB_SUSPENDED_PUBLICATION_IMPL_HPP_ */
