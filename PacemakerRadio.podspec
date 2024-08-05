Pod::Spec.new do |s|
  s.name             = 'PacemakerRadio'
  s.version          = '0.7.0'
  s.summary          = 'This library contains the Pacemaker Radio Engine and exposes functions to use it.'
  s.description      = 'This library contains the Pacemaker Radio Engine and exposes functions to use it.'
  s.homepage         = 'https://www.tunedglobal.com'
  s.license          = { :type => 'MIT', :file => 'builds/PacemakerRadio/0.7.0/PacemakerRadio-LICENSE' }
  s.author           = { 'vic' => 'victor.garcia@tunedglobal.com' }
  s.source           = { :git => 'https://github.com/tunedglobal/automix-ios-framework.git',
                         :tag => 'PacemakerRadio/' + s.version.to_s,
                         :submodules => true }
  s.dependency 'nlohmann_json', '~>3.5.0'
  s.dependency 'glm', '~>0.9.4.3'
  s.dependency 'OpenSSL-Universal', '~>1.1.1900'
  s.frameworks = 'Accelerate', 'AudioToolbox', 'Security', 'AVFoundation', 'SafariServices'
  s.vendored_frameworks = "builds/PacemakerRadio/0.7.0/PacemakerRadio.xcframework"
  s.platform = :ios
  s.swift_version    = '5.5'
  s.ios.deployment_target  = '13.0'
  s.requires_arc = true
end
