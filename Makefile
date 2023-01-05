all:
	@echo "--- START BUILD ---"
	make  --directory=dynamic_allocation/
	make  --directory=list/
	make  --directory=queue/
	make  --directory=stack/
	make  --directory=tree/
	@echo "--- DONE BUILD ---"
clean:
	@echo "--- START BUILD ---"
	make  --directory=dynamic_allocation/ clean
	make  --directory=list/ clean
	make  --directory=queue/ clean
	make  --directory=stack/ clean
	make  --directory=tree/ clean
	@echo "--- DONE BUILD ---"