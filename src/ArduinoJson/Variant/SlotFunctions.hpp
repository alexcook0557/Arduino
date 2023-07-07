// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2023, Benoit BLANCHON
// MIT License

#pragma once

#include <ArduinoJson/Polyfills/assert.hpp>
#include <ArduinoJson/Variant/VariantData.hpp>

ARDUINOJSON_BEGIN_PRIVATE_NAMESPACE

inline size_t slotSize(const VariantSlot* var) {
  size_t n = 0;
  while (var) {
    n++;
    var = var->next();
  }
  return n;
}

inline void VariantSlot::release(ResourceManager* resources) {
  if (flags_ & OWNED_KEY_BIT)
    resources->dereferenceString(ownedKey_);
  data()->setNull(resources);
}

ARDUINOJSON_END_PRIVATE_NAMESPACE
