env = Environment(tools = ['default', 'cxxtest'])
env.Append(CPPFLAGS=['-Wall','-g'])
Export('env')

#build external library
utils = env.SConscript('utils/SConscript' )
env.Append(LIBS=utils)

#build OO-IO library
ooio = SConscript('SConscript')