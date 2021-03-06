/**
 * This file is part of Pandion.
 *
 * Pandion is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Pandion is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Pandion.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Filename:    SASL.h
 * Author(s):   Dries Staelens
 * Copyright:   Copyright (c) 2009 Dries Staelens
 * Description: TODOTODOTODO
 */
#pragma once
#include "DispInterfaceImpl.h"
#include "SCRAM.h"
#include "SSPI.h"
#include "GSSAPI.h"

class SASL :
	public DispInterfaceImpl<ISASL>
{
private:
	SCRAM  m_SCRAM;
	SSPI   m_SSPI;
	GSSAPI m_GSSAPI;
public:
	SASL();
	~SASL();

	STDMETHOD(PlainGenerateResponse)(
		BSTR jid, BSTR username, BSTR password, BSTR *strBase64);
	STDMETHOD(DigestGenerateResponse)(
		BSTR username, BSTR realm, BSTR password, BSTR nonce,
		BSTR cnonce, BSTR digest_uri, BSTR nc, BSTR qop, BSTR *strDigest);
	STDMETHOD(get_SCRAM)(VARIANT* pDispatch);
	STDMETHOD(get_SSPI)(VARIANT* pDispatch);
	STDMETHOD(get_GSSAPI)(VARIANT* pDispatch);

private:
	void HexString(const unsigned char *binaryData, char *hexString, int n);
};
