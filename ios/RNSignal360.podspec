
Pod::Spec.new do |s|
  s.name         = "RNSignal360"
  s.version      = "1.0.0"
  s.summary      = "RNSignal360"
  s.description  = <<-DESC
                  RNSignal360
                   DESC
  s.homepage     = ""
  s.license      = "MIT"
  # s.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  s.author             = { "author" => "author@domain.cn" }
  s.platform     = :ios, "7.0"
  s.source       = { :git => "https://github.com/author/RNSignal360.git", :tag => "master" }
  s.source_files  = "RNSignal360/**/*.{h,m}"
  s.requires_arc = true


  s.dependency "React"
  #s.dependency "others"

end

  