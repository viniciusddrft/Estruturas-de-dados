all:
	@echo "--- START BUILD ---"
	make  --directory=dynamic_allocation/
	make  --directory=list/
	make  --directory=queue/
	make  --directory=stack/
	make  --directory=tree/
	make  --directory=linear-structure-search/
	make  --directory=linear-structure-search/hash-table/
	@echo "--- DONE BUILD ---"
clean:
	@echo "--- START CLEAN ---"
	make  --directory=dynamic_allocation/ clean
	make  --directory=list/ clean
	make  --directory=queue/ clean
	make  --directory=stack/ clean
	make  --directory=tree/ clean
	make  --directory=linear-structure-search/ clean
	make  --directory=linear-structure-search/hash-table/ clean
	@echo "--- DONE CLEAN ---"
