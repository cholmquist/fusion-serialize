/*=============================================================================
    Copyright (c) 2011 Christian Holmquist

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_FUSION_SEQUENCE_SERIALIZATION_OARCHIVE
#define BOOST_FUSION_SEQUENCE_SERIALIZATION_OARCHIVE

#include <boost/fusion/support/is_sequence.hpp>
#include <boost/fusion/sequence/serialization/detail/save.hpp>
#include <boost/archive/is_archive.hpp>
#include <boost/mpl/and.hpp>

namespace boost { namespace fusion
{
	template <typename OArchive, typename Sequence>
	OArchive& save(OArchive& ar, Sequence const& seq)
	{
		detail::save_sequence(ar, seq);
		return ar;
	}

	namespace operators
    {
		template <typename Archive, typename Sequence>
		typename enable_if<
			mpl::and_<archive::is_oarchive<Archive>, fusion::traits::is_sequence<Sequence> >
			, Archive&
		>::type
		operator<<(Archive& ar, Sequence const& seq)
		{
			return fusion::save(ar, seq);
		}
	}
	using operators::operator<<;
}}

#endif
