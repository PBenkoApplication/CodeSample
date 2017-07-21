#ifndef SHADOWPROPERTIES_H
#define SHADOWPROPERTIES_H

namespace BAME
{
	class ShadowProperties
	{
	public:

		enum class PCF_Kernel
		{
			PCF_4x4=4,
			PCF_8x8=8,
			PCF_16x16=16
		};

		ShadowProperties();

		void SetShadowCasting(bool enabled);
		void SetShadowPCF(bool enabled);
		void SetPCFKernelFactor(PCF_Kernel const& pcfKernel);


		bool IsShadowCaster() const;
		bool IsPCFShadowEnabled() const;
		int GetPCFKernelFactor() const;

	private:
		bool mIsShadowCaster;
		bool mIsSoftenWithPCF;

		int mPCFKernelFactor;
	};
}
#endif