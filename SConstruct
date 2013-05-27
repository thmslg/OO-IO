env = Environment(tools = ['default', 'cxxtest'])
env.Append(CPPFLAGS=['-Wall','-g'])
Export('env')

SConscript('SConscript', variant_dir='build', duplicate=0)

#env.Library('prog', libraries)