Import('env')
localEnv = env.Clone()

sources = [
'Sources/ListenableSampledInput.cpp',
'Sources/InvertedListenableSampledInput.cpp',
'Sources/SingleEndedADCInput.cpp',
'Sources/MPXV7002.cpp',
]

ooio = localEnv.Library('OO-IO', sources )
localEnv.Prepend(LIBS=ooio)

testList =  [
'UnitTest/ListenableSampledInput.t.h',
'UnitTest/InvertedListenableSampledInput.t.h',
'UnitTest/SingleEndedADCInput.t.h',
]

localEnv.CxxTest('testrunner',testList, CXXFLAGS='-Wall -W -Wextra')

Return('ooio')