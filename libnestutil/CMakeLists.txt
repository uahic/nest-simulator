# libnestutil/CMakeLists.txt
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

set( nestutil_sources
    stopwatch.h stopwatch.cpp
    numerics.h numerics.cpp
    propagator_stability.h propagator_stability.cpp
    lockptr.h
    sparseconfig.h
    template_util.h
    type_traits.h
    libc_allocator_with_realloc.h
    hashtable-common.h
    sparsetable.h
    compose.hpp
    string_utils.h
    logging.h
    logging_event.h logging_event.cpp
    )

add_library( nestutil ${nestutil_sources} )

target_link_libraries( nestutil ${GSL_LIBRARIES} )

target_include_directories( nestutil PRIVATE
    ${PROJECT_BINARY_DIR}/libnestutil
    )

install( TARGETS nestutil
    LIBRARY DESTINATION ${INSTALL_LIB_DIR}
    ARCHIVE DESTINATION ${INSTALL_LIB_DIR}
    RUNTIME DESTINATION ${INSTALL_BIN_DIR}
    )
