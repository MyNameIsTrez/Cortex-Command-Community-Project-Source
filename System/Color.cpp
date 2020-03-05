#include "Color.h"
#include "RTETools.h"

namespace RTE {

	const std::string Color::ClassName = "Color";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int Color::Create() {
		// Read all the properties
		if (Serializable::Create() < 0) { return -1; }
		RecalculateIndex();
		return 0;
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int Color::ReadProperty(std::string propName, Reader &reader) {
		if (propName == "R") {
			reader >> m_R;
		} else if (propName == "G") {
			reader >> m_G;
		} else if (propName == "B") {
			reader >> m_B;
		} else {
			// See if the base class(es) can find a match instead
			return Serializable::ReadProperty(propName, reader);
		}
		return 0;
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int Color::Save(Writer &writer) const {
		Serializable::Save(writer);

		writer.NewProperty("R");
		writer << m_R;
		writer.NewProperty("G");
		writer << m_G;
		writer.NewProperty("B");
		writer << m_B;

		return 0;
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void Color::SetRGBWithIndex(unsigned char index) {
		m_Index = index;

		RGB color;
		get_color((int)m_Index, &color);

		m_R = color.r * 4;
		m_G = color.g * 4;
		m_B = color.b * 4;
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	unsigned char Color::RecalculateIndex() { return m_Index = makecol8(m_R, m_G, m_B); }
}