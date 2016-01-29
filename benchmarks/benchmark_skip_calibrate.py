import nest

spike_rate = 1000.0
trials = 100
trial_duration = 20.0
network_module = "brunel_alpha_nest"
# For brunel: set the 'order' 
network_args = [4000]
network_kwargs = {}

# Without skip_calibrate_nodes
benchmark_utils.setup_kernel()
benchmark_utils.load_network(network_module, *network_args, **network_kwargs)
min_delay_before_sim1 = nest.GetKernelStatus({'min_delay'})[0]
nest.SetKernelStatus({'skip_calibrate_nodes': False})
trial_duration_sim1 = round(trial_duration / min_delay_before_sim1) * min_delay_before_sim1
duration_with_calibration = benchmark_utils.run(trials, trial_duration=trial_duration_sim1)
min_delay_after_sim1 = nest.GetKernelStatus({'min_delay'})

# With skip_calibrate_nodes
benchmark_utils.setup_kernel()
benchmark_utils.load_network(network_module, *network_args, **network_kwargs)
min_delay_before_sim2 = nest.GetKernelStatus({'min_delay'})[0]
nest.SetKernelStatus({'skip_calibrate_nodes': True})
trial_duration_sim2 = round(trial_duration / min_delay_before_sim2) * min_delay_before_sim2
duration_no_calibration = benchmark_utils.run(trials, trial_duration=trial_duration_sim2)
min_delay_after_sim2 = nest.GetKernelStatus({'min_delay'})

print( "Benchmark results:\n" )
print( "With node_calibration: {} seconds".format(duration_with_calibration) )
print( "Min-delay: before sim={}, after sim={}".format( min_delay_before_sim1, min_delay_after_sim1 ) )
print( "Trial-duration: {}".format(trial_duration_sim1) )
print( "Without node_calibration: {} seconds".format(duration_no_calibration) )
print( "Min-delay: before sim={}, after sim={}".format( min_delay_before_sim2, min_delay_after_sim2 ) )
print( "Trial-duration: {}".format(trial_duration_sim2) )




