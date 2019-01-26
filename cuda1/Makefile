NVCC = nvcc

helloCUDA: kernel.cu host.cu
	$(NVCC) -I ./ kernel.cu host.cu -o ass1

run:
	./ass1

clean:
	rm -rf ass1


