#  This program source code file is part of KICAD, a free EDA CAD application.
#
#  Copyright (C) 2015 Google, Michael Beardsworth <beardsworth@google.com>
#
#  This program is free software; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License
#  as published by the Free Software Foundation; either version 2
#  of the License, or (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, you may find one here:
#  http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
#  or you may search the http://www.gnu.org website for the version 2 license,
#  or you may write to the Free Software Foundation, Inc.,
#  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA

set( PREFIX ${DOWNLOAD_DIR}/gtest )
set (GTEST_ROOT ${PREFIX})

ExternalProject_Add( gtest
    PREFIX          "${PREFIX}"
    DOWNLOAD_DIR    "${DOWNLOAD_DIR}"
    URL             https://googletest.googlecode.com/files/gtest-1.7.0.zip
    #URL_MD5         ${GTEST_MD5}
    STAMP_DIR       "${PREFIX}"
    BUILD_IN_SOURCE 1
    INSTALL_COMMAND ""
)

set(GTEST_INCLUDE_DIR "${GTEST_ROOT}/src/gtest/include" )
set(GTEST_LIBRARY "${GTEST_ROOT}/src/gtest/libgtest.a" )
