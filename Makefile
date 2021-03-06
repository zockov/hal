DIRS := include/device src/vector
SVDS := $(wildcard svd/*.svd)
DEVS := $(SVDS:svd/%.svd=include/device/%.h)
VECT := $(SVDS:svd/%.svd=src/vector/%.cpp)

all: dirs $(DEVS) $(VECT)

.PHONY: dirs

dirs: ${DIRS}

${DIRS}:
	mkdir -p $@

include/device/%.h: svd/%.svd
	SVD2CPP $< > $@

src/vector/%.cpp: svd/%.svd
	SVD2CPP --interrupt $< > $@

clean:
	rm -rf $(DIRS)

