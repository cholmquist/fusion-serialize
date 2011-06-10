/*=============================================================================
    Copyright (c) 2011 Christian Holmquist

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/archive/is_archive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/detail/lightweight_test.hpp>

namespace archive = boost::archive;

struct not_an_archive
{
	void is_saving() {}
	void is_loading() {}
};

int main_is_archive()
{
	BOOST_MPL_ASSERT_NOT((archive::is_iarchive<int>));

	BOOST_MPL_ASSERT((archive::is_iarchive<archive::text_iarchive>));
	BOOST_MPL_ASSERT_NOT((archive::is_oarchive<archive::text_iarchive>));

	BOOST_MPL_ASSERT((archive::is_oarchive<archive::text_oarchive>));
	BOOST_MPL_ASSERT_NOT((archive::is_iarchive<archive::text_oarchive>));

	BOOST_MPL_ASSERT_NOT((archive::is_iarchive<not_an_archive>));
	BOOST_MPL_ASSERT_NOT((archive::is_oarchive<not_an_archive>));

	return boost::report_errors();
}
