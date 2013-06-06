Import('env')
localEnv = env.Clone()

sources = [
'Sources/ListenableSampledInput.cpp',
'Sources/InvertedListenableSampledInput.cpp',
]

ooio = localEnv.Library('OO-IO', sources )
localEnv.Prepend(LIBS=library)

testList =  [
'UnitTest/ListenableSampledInput.t.h',
'UnitTest/InvertedListenableSampledInput.t.h',
]

localEnv.CxxTest('testrunner',testList, CXXFLAGS='-Wall -W -Wextra')

Return('ooio')