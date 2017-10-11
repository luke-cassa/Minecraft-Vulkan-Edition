// Minecraft Vulkan Edition.cpp : definisce il punto di ingresso dell'applicazione console.
//

/*
#include <vulkan.h>
#include <iostream>
#include <string>

#define ASSERT_VULKAN(val)\
if(val != VK_SUCCESS){\
__debugbreak();\
}


VkInstance instance;
uint32_t deviceCount;

VkPhysicalDeviceFeatures features;
VkPhysicalDeviceProperties properties;
VkPhysicalDeviceMemoryProperties memProp;
uint32_t apiVersion = properties.apiVersion;




void starConsole(VkPhysicalDevice &device) {
vkGetPhysicalDeviceProperties(device,&properties);
vkGetPhysicalDeviceFeatures(device, &features);
vkGetPhysicalDeviceMemoryProperties(device, &memProp);
std::cout << "Vulkan interactive console version 1.0.0\n" << std::endl;
std::cout << "Type -h for help\n" << std::endl;


uint32_t queueCount;
vkGetPhysicalDeviceQueueFamilyProperties(device, &queueCount,NULL);
while (true)
{
std::cout << "> ";
std::string c;
std::cin >> c;
if (c == "-h") {
std::cout << "-displayInfo to display graphic card infos \n-displayFeatures to view graphic card features\n-displayMemory to display memory" << std::endl;
}
if(c == "-displayFeatures") {

std::cout << std::endl;
std::cout<< "Robust buffer access                         : "<<features.robustBufferAccess << std::endl;
std::cout<< "Full draw index Uint32                       : "<<features.fullDrawIndexUint32 << std::endl;
std::cout<< "Image cube array                             : "<<features.imageCubeArray << std::endl;
std::cout<< "Indipendent blend                            : "<<features.independentBlend << std::endl;
std::cout<< "Geometry shader                              : "<<features.geometryShader << std::endl;
std::cout<< "Tassellation shader                          : "<<features.tessellationShader << std::endl;
std::cout<< "Sample rate shading                          : "<<features.sampleRateShading << std::endl;
std::cout<< "Dual source blend                            : "<<features.dualSrcBlend << std::endl;
std::cout<< "Logic OP                                     : "<<features.logicOp << std::endl;
std::cout<< "Indirect multidraw                           : "<<features.multiDrawIndirect << std::endl;
std::cout<< "Indirect draw first instance                 : "<<features.drawIndirectFirstInstance << std::endl;
std::cout<< "Depth clamp                                  : "<<features.depthClamp << std::endl;
std::cout<< "Depth bias clamp                             : "<<features.depthBiasClamp << std::endl;
std::cout<< "Non solid fill-mode                          : "<<features.fillModeNonSolid << std::endl;
std::cout<< "Depth bounds                                 : "<<features.depthBounds << std::endl;
std::cout<< "Wide lines                                   : "<<features.wideLines << std::endl;
std::cout<< "Large points                                 : "<<features.largePoints << std::endl;
std::cout<< "Alpha to one                                 : "<<features.alphaToOne << std::endl;
std::cout<< "Multi viewPort                               : "<<features.multiViewport << std::endl;
std::cout<< "Sampler anisotropy                           : "<<features.samplerAnisotropy << std::endl;
std::cout<< "ETC2 texture compression                     : "<<features.textureCompressionETC2 << std::endl;
std::cout<< "ASTC_LDR texture compression                 : "<<features.textureCompressionASTC_LDR << std::endl;
std::cout<< "BC texture compression                       : "<<features.textureCompressionBC << std::endl;
std::cout<< "Query precise occlusion                      : "<<features.occlusionQueryPrecise << std::endl;
std::cout<< "Pipeline query statistic                     : "<<features.pipelineStatisticsQuery << std::endl;
std::cout<< "Vertex pipeline stores and atomics           : "<<features.vertexPipelineStoresAndAtomics << std::endl;
std::cout<< "Fragment stores and atomics                  : "<<features.fragmentStoresAndAtomics << std::endl;
std::cout<< "Tassellation and geometry shader point size  : "<<features.shaderTessellationAndGeometryPointSize << std::endl;
std::cout<< "Shader image ghater extended                 : "<<features.shaderImageGatherExtended << std::endl;
std::cout<< "Shader storage image extended formats        : "<<features.shaderStorageImageExtendedFormats << std::endl;
std::cout<< "Shader storage image multisample             : "<<features.shaderStorageImageMultisample << std::endl;
std::cout<< "Shader storage image read without format     : "<<features.shaderStorageImageReadWithoutFormat << std::endl;
std::cout<< "Shader storage image write without format    : "<<features.shaderStorageImageWriteWithoutFormat << std::endl;
std::cout<< "Shader uniform buffer array dynamic indexing : "<<features.shaderUniformBufferArrayDynamicIndexing << std::endl;
std::cout<< "Shader sampled image array dynamic indexing  : "<<features.shaderSampledImageArrayDynamicIndexing << std::endl;
std::cout<< "Shader storage buffer array dynamic indexing : "<<features.shaderStorageBufferArrayDynamicIndexing << std::endl;
std::cout<< "Shader storage image array dynamic indexing  : "<<features.shaderStorageImageArrayDynamicIndexing << std::endl;
std::cout<< "Shader clip distance                         : "<<features.shaderClipDistance << std::endl;
std::cout<< "Shader cull distance                         : "<<features.shaderCullDistance << std::endl;
std::cout<< "Shader float 64                              : "<<features.shaderFloat64 << std::endl;
std::cout<< "Shader int 64                                : "<<features.shaderInt64 << std::endl;
std::cout<< "Shader int 16                                : "<<features.shaderInt16 << std::endl;
std::cout<< "Shader resource residency                    : "<<features.shaderResourceResidency << std::endl;
std::cout<< "Shader resource minimum lod                  : "<<features.shaderResourceMinLod << std::endl;
std::cout<< "Sparse binding                               : "<<features.sparseBinding << std::endl;
std::cout<< "Sparse residency buffer                      : "<<features.sparseResidencyBuffer << std::endl;
std::cout<< "Sparse residency image 2D                    : "<<features.sparseResidencyImage2D << std::endl;
std::cout<< "Sparse residency image 3D                    : "<<features.sparseResidencyImage3D << std::endl;
std::cout<< "Sparse residency 2 samples                   : "<<features.sparseResidency2Samples << std::endl;
std::cout<< "Sparse residency 4 samples                   : "<<features.sparseResidency4Samples << std::endl;
std::cout<< "Sparse residency 8 samples                   : "<<features.sparseResidency8Samples << std::endl;
std::cout<< "Sparse residency 16 samples                  : "<<features.sparseResidency16Samples << std::endl;
std::cout<< "Sparse residency aliased                     : "<<features.sparseResidencyAliased << std::endl;
std::cout<< "Variable multisample rate                    : "<<features.variableMultisampleRate << std::endl;
std::cout<< "Inherited queries                            : "<<features.inheritedQueries << std::endl;

}
if (c == "-displayInfo") {
std::cout << "Device name:        " << properties.deviceName << std::endl;
std::cout << "Device type:        " << properties.deviceType << std::endl;
std::cout << "API version:        " << VK_VERSION_MAJOR(apiVersion) << "." << VK_VERSION_MINOR(apiVersion) << "." << VK_VERSION_PATCH(apiVersion) << std::endl;
std::cout << "Vendor ID:          " << properties.vendorID << std::endl;
std::cout << "Driver version:     " << properties.driverVersion << std::endl;
std::cout << "Device limitations: " << std::endl;
}
if (c == "-displayMemory") {
std::cout << memProp.memoryTypes << std::endl;
}
}
}




int main() {

VkApplicationInfo appInfo;
appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
appInfo.pNext = NULL;
appInfo.pApplicationName = "Minecraft Vulkan Edition";
appInfo.applicationVersion = VK_MAKE_VERSION(1,0,0);
appInfo.pEngineName = "Minecraft Vulkan Engine";
appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
appInfo.apiVersion = VK_API_VERSION_1_0;

VkInstanceCreateInfo instanceInfo;
instanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
instanceInfo.pNext = NULL;
instanceInfo.flags = 0;
instanceInfo.pApplicationInfo = &appInfo;
instanceInfo.enabledLayerCount = 0;
instanceInfo.ppEnabledLayerNames = NULL;
instanceInfo.enabledExtensionCount = 0;
instanceInfo.ppEnabledExtensionNames = NULL;

VkResult result = vkCreateInstance(&instanceInfo, NULL, &instance);

ASSERT_VULKAN(result);

result = vkEnumeratePhysicalDevices(instance,&deviceCount,NULL);
ASSERT_VULKAN(result);
std::cout << "Number of devices avaiable found : "<< deviceCount << std::endl;

VkPhysicalDevice* physicalDevice = new VkPhysicalDevice[deviceCount];

result = vkEnumeratePhysicalDevices(instance, &deviceCount, physicalDevice);
ASSERT_VULKAN(result);

for (unsigned int i = 0; i < deviceCount; i++) {
starConsole(physicalDevice[i]);
}

system("PAUSE");
return 0;
}
*/