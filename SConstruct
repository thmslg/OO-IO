env = Environment(tools = ['default', 'cxxtest'])
env.Append(CPPFLAGS=['-Wall','-g'])
Export('env')

ooio = SConscript('SConscript')

#env.Library('usableLibrary', ooio )