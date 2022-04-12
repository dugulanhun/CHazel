#pragma once

#include "Core.h"
#include "CHazel/Layer.h"

#include <vector>

namespace CHazel {

	class CHAZEL_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		// 层与覆层的分界线迭代器
		//std::vector<Layer*>::iterator m_LayerInsert;
		unsigned int m_LayerInsertIndex = 0;
	};

}