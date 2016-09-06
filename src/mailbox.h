//////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

#ifndef __OTSERV_MAILBOX_H__
#define __OTSERV_MAILBOX_H__

#include "const.h"
#include "cylinder.h"
#include "definitions.h"
#include "item.h"


class Mailbox : public Item, public Cylinder
{
public:
	Mailbox(uint16_t _type);
	~Mailbox() override;

	Mailbox* getMailbox() override
	{
		return this;
	}
	const Mailbox* getMailbox() const override
	{
		return this;
	}

	// cylinder implementations
	ReturnValue __queryAdd(int32_t index, const Thing* thing, uint32_t count, uint32_t flags) const override;
	ReturnValue
	__queryMaxCount(int32_t index, const Thing* thing, uint32_t count, uint32_t& maxQueryCount, uint32_t flags) const override;
	ReturnValue __queryRemove(const Thing* thing, uint32_t count, uint32_t flags) const override;
	Cylinder* __queryDestination(int32_t& index, const Thing* thing, Item** destItem, uint32_t& flags) override;

	void __addThing(Thing* thing) override;
	void __addThing(int32_t index, Thing* thing) override;

	void __updateThing(Thing* thing, uint16_t itemId, uint32_t count) override;
	void __replaceThing(uint32_t index, Thing* thing) override;

	void __removeThing(Thing* thing, uint32_t count) override;

	void postAddNotification(Thing* thing, const Cylinder* oldParent, int32_t index, cylinderlink_t link = LINK_OWNER) override;
	void postRemoveNotification(Thing* thing,
	                            const Cylinder* newParent,
	                            int32_t index,
	                            bool isCompleteRemoval,
	                            cylinderlink_t link = LINK_OWNER) override;

	bool getReceiver(Item* item, std::string& name, uint32_t& dpnum);
	bool sendItem(Item* item);
	bool canSend(const Item* item) const;
};

#endif
