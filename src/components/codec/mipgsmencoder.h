/*
    
  This file is a part of EMIPLIB, the EDM Media over IP Library.
  
  Copyright (C) 2006-2011  Hasselt University - Expertise Centre for
                      Digital Media (EDM) (http://www.edm.uhasselt.be)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  
  USA

*/

/**
 * \file mipgsmencoder.h
 */

#ifndef MIPGSMENCODER_H

#define MIPGSMENCODER_H

#include "mipconfig.h"

#ifdef MIPCONFIG_SUPPORT_GSM

#include "mipcomponent.h"
#include "miptime.h"
#include <list>

class MIPEncodedAudioMessage;
struct gsm_state;

/** Compress audio using the GSM 06.10 codec.
 *  Using this component, 16 bit signed (native encoded) raw audio messages can 
 *  be compressed using the GSM 06.10 codec. Messages generated by this component 
 *  are encoded audio messages with subtype MIPENCODEDAUDIOMESSAGE_TYPE_GSM.
 */
class EMIPLIB_IMPORTEXPORT MIPGSMEncoder : public MIPComponent
{
public:
	MIPGSMEncoder();
	~MIPGSMEncoder();

	/** Initialize the GSM encoding component. */
	bool init();

	/** Clean up the GSM encoder. */
	bool destroy();

	bool push(const MIPComponentChain &chain, int64_t iteration, MIPMessage *pMsg);
	bool pull(const MIPComponentChain &chain, int64_t iteration, MIPMessage **pMsg);
private:
	void clearMessages();
	
	bool m_init;
	struct gsm_state *m_pState;
	int64_t m_prevIteration;

	std::list<MIPEncodedAudioMessage *> m_messages;
	std::list<MIPEncodedAudioMessage *>::const_iterator m_msgIt;
};	

#endif // MIPCONFIG_SUPPORT_GSM

#endif // MIPGSMENCODER_H

