#!/bin/bash

if [ ! -d nanomsg ]; then
	mkdir -p nanomsg/nanomsg
fi

NN=nanomsg
NN_DIR=$(cd $(dirname .) && pwd)/nanomsg

mkdir temp

pushd temp
git clone git@github.com:/nanomsg/nanomsg.git
pushd $NN
./autogen.sh
./configure
cp -r src $NN_DIR/nanomsg
cp COPYING $NN_DIR/nanomsg
popd

git clone git@github.com:nanomsg/cppnanomsg.git
pushd cppnanomsg
cp nn.hpp $NN_DIR
popd

popd

rm -rf temp
