# testsuite/mpitests/CMakeLists.txt
#
# This file is part of NEST.
#
# Copyright (C) 2004 The NEST Initiative
#
# NEST is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# NEST is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with NEST.  If not, see <http://www.gnu.org/licenses/>.

if ( HAVE_MPI )
  # add mpitests files
  file( GLOB scripts RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.sli )

  foreach ( script ${scripts} )
    add_test( NAME mpitests/${script}
        COMMAND ${CMAKE_INSTALL_PREFIX}/${INSTALL_BIN_DIR}/nest_indirect
        ${CMAKE_INSTALL_PREFIX}/${INSTALL_DOC_DIR}/mpitests/${script} # use the installed version
        )
  endforeach ()
endif ()
