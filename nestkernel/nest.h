/*
 *  nest.h
 *
 *  This file is part of NEST.
 *
 *  Copyright (C) 2004 The NEST Initiative
 *
 *  NEST is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  NEST is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with NEST.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef NEST_H
#define NEST_H

// C++ includes:
#include <ostream>

// Includes from libnestutil:
#include "logging.h"

// Includes from librandom:
#include "randomgen.h"

// Includes from nestkernel:
#include "nest_datums.h"
#include "nest_time.h"
#include "nest_types.h"

// Includes from sli:
#include "arraydatum.h"
#include "dictdatum.h"

namespace nest
{

void init_nest( int* argc, char** argv[] );
void fail_exit( int exitcode );

void install_module( const std::string& module_name );

void reset_kernel();
void reset_network();

void enable_dryrun_mode( const index n_procs );

void register_logger_client( const deliver_logging_event_ptr client_callback );
void print_network( index gid, index depth, std::ostream& out = std::cout );

librandom::RngPtr get_vp_rng_of_gid( index target );
librandom::RngPtr get_vp_rng( thread tid );
librandom::RngPtr get_global_rng();

void set_kernel_status( const DictionaryDatum& dict );
DictionaryDatum get_kernel_status();

void set_node_status( const index node_id, const DictionaryDatum& dict );
DictionaryDatum get_node_status( const index node_id );

void set_connection_status( const ConnectionDatum& conn,
  const DictionaryDatum& dict );
DictionaryDatum get_connection_status( const ConnectionDatum& conn );

index create( const Name& model_name, const index n );

void connect( const GIDCollection& sources,
  const GIDCollection& targets,
  const DictionaryDatum& connectivity,
  const DictionaryDatum& synapse_params );

ArrayDatum get_connections( const DictionaryDatum& dict );

void simulate( const double_t& t );
void resume_simulation();

void copy_model( const Name& oldmodname,
  const Name& newmodname,
  const DictionaryDatum& dict );

void set_model_defaults( const Name& model_name, const DictionaryDatum& );
DictionaryDatum get_model_defaults( const Name& model_name );

void set_num_rec_processes( const index n_rec_procs );

void change_subnet( const index node_gid );
index current_subnet();

ArrayDatum get_nodes( const index subnet_id,
  const DictionaryDatum& params,
  const bool include_remotes,
  const bool return_gids_only );

ArrayDatum get_leaves( const index subnet_id,
  const DictionaryDatum& params,
  const bool include_remotes );

ArrayDatum get_children( const index subnet_id,
  const DictionaryDatum& params,
  const bool include_remotes );

void restore_nodes( const ArrayDatum& node_list );
}


#endif /* NEST_H */
