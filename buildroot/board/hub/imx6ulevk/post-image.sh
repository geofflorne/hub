#!/usr/bin/env bash

main()
{
	genimage \
		--rootpath "${TARGET_DIR}" \
		--tmppath "${BUILD_DIR}/genimage.tmp" \
		--inputpath "${BINARIES_DIR}" \
		--outputpath "${BINARIES_DIR}" \
		--config "${PWD}/board/hub/imx6ulevk/genimage.cfg"

	exit $?
}

main $@
