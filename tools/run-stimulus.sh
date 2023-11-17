python3 -m venv .venv
.venv/bin/pip install -r ./tools/build-requirements.txt

.venv/bin/stimulus \
           -f vendor/igraph/interfaces/functions.yaml \
           -f tools/stimulus/functions-js.yaml \
           -i tools/stimulus/bind.cpp.in \
           -o src/bind.cpp \
           -t vendor/igraph/interfaces/types.yaml \
           -t tools/stimulus/types-js.yaml \
           -l js
