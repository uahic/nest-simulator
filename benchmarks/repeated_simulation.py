import time
import importlib
import nest





def setup_kernel():
    nest.ResetKernel()
    N_vp = nest.GetKernelStatus(['total_num_virtual_procs'])[0]
    nest.SetKernelStatus({'rng_seeds' : [1000] * N_vp})
    nest.SetKernelStatus({'grng_seed' : 1000})

def load_network(module_name, *args, **kwargs):
    network_module = importlib.import_module(module_name)
    network_module.create_network(*args, **kwargs)
    

def run(num_trials, trial_duration=20.0):
    start = time.clock()

    for n in range(num_trials):
        #nest.SetStatus(pg, {'origin': nest.GetKernelStatus()['time']})
        nest.Simulate(trial_duration)

    end = time.clock()
    duration = end - start
    return duration




#import nest.raster_plot
#nest.raster_plot.from_device(sd, hist=True, hist_binwidth=100.,
#                             title='Repeated stimulation by Poisson generator')
