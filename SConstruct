env = Environment(tools = ['default', 'cxxtest'])
env.Append(CPPFLAGS=['-Wall','-g'])
Export('env')

#build external library
# WARNING We suppose tht "Utils" folder is at the same "component" level as here.
utils = env.SConscript('../Utils/SConscript' )
env.Append(LIBS=utils)

#build OO-IO library
ooio = SConscript('SConscript')