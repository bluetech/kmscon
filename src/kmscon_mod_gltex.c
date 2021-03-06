/*
 * kmscon - OpenGL Texture based rendering backend module
 *
 * Copyright (c) 2011-2013 David Herrmann <dh.herrmann@googlemail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
 * OpenGL Texture based rendering backend module
 * This module provides the gltex renderer backend.
 */

#include <errno.h>
#include <stdlib.h>
#include "text.h"
#include "kmscon_module_interface.h"
#include "shl_log.h"

#define LOG_SUBSYSTEM "mod_gltex"

static int kmscon_gltex_load(void)
{
	int ret;

	kmscon_text_gltex_ops.owner = KMSCON_THIS_MODULE;
	ret = kmscon_text_register(&kmscon_text_gltex_ops);
	if (ret) {
		log_error("cannot register gltex renderer");
		return ret;
	}

	return 0;
}

static void kmscon_gltex_unload(void)
{
	kmscon_text_unregister(kmscon_text_gltex_ops.name);
}

KMSCON_MODULE(NULL, kmscon_gltex_load, kmscon_gltex_unload, NULL);
