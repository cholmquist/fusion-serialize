/*=============================================================================
    Copyright (c) 2001-2006 Joel de Guzman
	Copyright (c) 2011 Christian Holmquist

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_FUSION_SEQUENCE_SERIALIZATION_DETAIL_SAVE
#define BOOST_FUSION_SEQUENCE_SERIALIZATION_DETAIL_SAVE

#include <boost/fusion/sequence/intrinsic/begin.hpp>
#include <boost/fusion/sequence/intrinsic/end.hpp>
#include <boost/fusion/iterator/deref.hpp>
#include <boost/fusion/iterator/next.hpp>
#include <boost/fusion/iterator/equal_to.hpp>
#include <boost/mpl/bool.hpp>

namespace boost { namespace fusion { namespace detail
{
    struct save_sequence_loop
    {
        template <typename OArchive, typename First, typename Last>
        static void
        call(OArchive&, First const&, Last const&, mpl::true_)
        {
        }

        template <typename OArchive, typename First, typename Last>
        static void
        call(OArchive& ar, First const& first, Last const& last, mpl::false_)
        {
            result_of::equal_to<
                typename result_of::next<First>::type
              , Last
            >
            is_last;

            ar << *first;
            call(ar, fusion::next(first), last, is_last);
        }

        template <typename OArchive, typename First, typename Last>
        static void
        call(OArchive& ar, First const& first, Last const& last)
        {
            result_of::equal_to<First, Last> eq;
            call(ar, first, last, eq);
        }
    };

    template <typename OArchive, typename Sequence>
    inline void
    save_sequence(OArchive& ar, Sequence const& seq)
    {
        save_sequence_loop::call(ar, fusion::begin(seq), fusion::end(seq));
    }
}}}

#endif
