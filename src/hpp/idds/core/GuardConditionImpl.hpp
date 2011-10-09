#ifndef OMG_IDDS_GUARD_CONDITION_IMPL_HPP_
#define OMG_IDDS_GUARD_CONDITION_IMPL_HPP_

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

#include <idds/core/FunctorHolder.hpp>
#include <idds/core/ConditionImpl.hpp>

namespace idds { namespace core {

   class GuardConditionImpl : public ConditionImpl {
   public:
      GuardConditionImpl()
      :  trigger_(false),
         fholder_(0)
      { }

      template <typename Functor>
      GuardConditionImpl(const Functor& func)
      :  trigger_(false),
         fholder_(new VoidFunctorHolder<Functor>(func))
      { }

      virtual ~GuardConditionImpl() {
         delete fholder_;
      }


      using ConditionImpl::trigger_value;

      virtual void trigger_value(bool b) {
         trigger_ = b;
      }

      virtual  void dispatch() {
          if (trigger_)
              fholder_->invoke();
      }

   public:
      template <typename Functor>
      void set_handler(const Functor& func) {
         idds::core::FunctorHolder* tmp = fholder_;
         fholder_ = new idds::core::VoidFunctorHolder<Functor>(func);
         if (tmp != 0)
            delete tmp;
      }

      void reset_handler() {
          idds::core::FunctorHolder* tmp = fholder_;
          fholder_ = 0;
          delete tmp;
      }

   private:
      GuardConditionImpl& operator= (const GuardConditionImpl&);
      GuardConditionImpl(const GuardConditionImpl&);

   private:
      bool trigger_;
      idds::core::FunctorHolder* fholder_;

   };

} }
#endif /* OMG_IDDS_GUARD_CONDITION_IMPL_HPP_ */
